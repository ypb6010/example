#include "XVideoWidget.h"
#include <QGLShaderProgram>
#include <QTimer>
#include <QDebug>
#include <gl/GL.h>
#define A_VER 3
#define T_VER 4

///自动加引号
#define GET_SHADER(x) #x


///片元shader
#if 0
const char* tString =
"#ifdef GL_ES\n"
"precision mediump float;\n"
"#endif\n"
"varying vec2 textureOut;\n"
"uniform sampler2D tex_y;\n"
"uniform sampler2D tex_u;\n"
"uniform sampler2D tex_v;\n"
"void main(void)\n"
"{\n"
"vec3 yuv;\n"
"vec3 rgb;\n"
"yuv.x = texture2D(tex_y, textureOut).r;\n"
"yuv.y = texture2D(tex_u, textureOut).r - 0.5;\n"
"yuv.z = texture2D(tex_v, textureOut).r - 0.5;\n"
"rgb = mat3(1.0, 1.0, 1.0,\n"
"0.0, -0.39465, 2.03211,\n"
"1.13983, -0.58060, 0.0) * yuv;\n"
"gl_FragColor = vec4(rgb, 1.0);\n"
"}";
#endif

///顶点shader
const char* vString = GET_SHADER(
	attribute vec4 vertexIn;
	attribute vec2 textureIn;
	varying vec2 textureOut;
void main(void)
{
	gl_Position = vertexIn;
	textureOut = textureIn;
}
);

const char* tString = GET_SHADER(
\n#ifdef GL_ES\n
precision mediump float;\n
\n#endif\n
varying vec2 textureOut;
uniform sampler2D tex_y;
uniform sampler2D tex_u;
uniform sampler2D tex_v; 
void main(void)
{
	vec3 yuv;
	vec3 rgb;
	yuv.x = texture2D(tex_y, textureOut).r;
	yuv.y = texture2D(tex_u, textureOut).r - 0.5;
	yuv.z = texture2D(tex_v, textureOut).r - 0.5;
	rgb = mat3(1.0, 1.0, 1.0,
	0.0, -0.39465, 2.03211,
	1.13983, -0.58060, 0.0) * yuv;
	gl_FragColor = vec4(  rgb, 1.0);
}
);

///准备YUV数据
///ffmpeg -i sss.mp4 -t 10 -s 240x128 -pix_fmt yuv420p out240x128.yuv
XVideoWidget::XVideoWidget(QWidget *parent)
	: QOpenGLWidget(parent)
{

}

XVideoWidget::~XVideoWidget()
{
}

void XVideoWidget::init(int nWidth, int nHeight)
{
	QMutexLocker locker(&m_mut);
	m_nWidth = nWidth;
	m_nHeight = nHeight;
	delete[] datas[0];
	delete[] datas[1];
	delete[] datas[2];
	///分配材质内存空间
	datas[0] = new uint8_t[m_nWidth * m_nHeight];		///Y
	datas[1] = new uint8_t[m_nWidth * m_nHeight / 4];	///U
	datas[2] = new uint8_t[m_nWidth * m_nHeight / 4];	///v

	if (texs[0])
	{
		glDeleteTextures(3, texs);
	}
	///创建材质
	glGenTextures(3, texs);

	///Y
	glBindTexture(GL_TEXTURE_2D, texs[0]);
	///放大过滤，线性插值
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	///创建材质显卡内存空间
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, m_nWidth, m_nHeight, 0, GL_RED, GL_UNSIGNED_BYTE, 0);

	///u
	glBindTexture(GL_TEXTURE_2D, texs[1]);
	///放大过滤，线性插值
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	///创建材质显卡内存空间
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, m_nWidth / 2, m_nHeight / 2, 0, GL_RED, GL_UNSIGNED_BYTE, 0);

	///v
	glBindTexture(GL_TEXTURE_2D, texs[2]);
	///放大过滤，线性插值
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	///创建材质显卡内存空间
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, m_nWidth / 2, m_nHeight / 2, 0, GL_RED, GL_UNSIGNED_BYTE, 0);
}

void XVideoWidget::paintVideo(AVFrame* frame)
{
	if (!frame)
	{
		return;
	}
	do
	{
		QMutexLocker locker(&m_mut);
		if (!datas[0] || frame->height * frame->width == 0 || frame->width != m_nWidth || frame->height != m_nHeight)
		{
			av_frame_free(&frame);
			return;
		}
		if (m_nWidth == frame->linesize[0])
		{

			memcpy_s(datas[0], m_nWidth * m_nHeight, frame->data[0], m_nHeight * m_nWidth);
			memcpy_s(datas[1], m_nWidth * m_nHeight / 4, frame->data[1], m_nHeight * m_nWidth / 4);
			memcpy_s(datas[2], m_nWidth * m_nHeight / 4, frame->data[2], m_nHeight * m_nWidth / 4);
		}
		///行对齐拷贝
		else
		{
			for (int i = 0; i < m_nHeight; ++i)
			{
				memcpy_s(datas[0] + m_nWidth * i, m_nWidth, frame->data[0] + frame->linesize[0] * i, m_nWidth);
			}
			for (int i = 0; i < m_nHeight / 2; ++i)
			{
				memcpy_s(datas[1] + m_nWidth / 2 * i, m_nWidth, frame->data[1] + frame->linesize[1] * i, m_nWidth);
			}
			for (int i = 0; i < m_nHeight / 2; ++i)
			{
				memcpy_s(datas[2] + m_nWidth / 2 * i, m_nWidth, frame->data[2] + frame->linesize[2] * i, m_nWidth);
			}
		}
	} while (false);
	av_frame_free(&frame);
	QMetaObject::invokeMethod(this, "update", Qt::QueuedConnection);
}

void XVideoWidget::initializeGL()
{

	QMutexLocker locker(&m_mut);

	debug_out << "初始化" << '\t' <<"initializeGL"<< '\n';
	///初始化opengl QOpenGLFunctions继承
	initializeOpenGLFunctions();
	
	///program加载shader脚本
	auto res = m_pProgram.addShaderFromSourceCode(QGLShader::Fragment, tString);
	debug_out << res << '\n';
	res = m_pProgram.addShaderFromSourceCode(QGLShader::Vertex, vString);
	debug_out << res << '\n';

	///设置顶点坐标的变量
	m_pProgram.bindAttributeLocation("vertexIn", A_VER);

	///设置材质坐标
	m_pProgram.bindAttributeLocation("textureIn", T_VER);
	res = m_pProgram.link();
	debug_out << "m_pProgram->link() :" << res << '\n';
	res = m_pProgram.bind();
	debug_out << "m_pProgram->bind() :" << res << '\n';

	///顶点坐标
	static const GLfloat ver[] = {
		-1.0f,-1.0f,
		1.0f,-1.0f,
		-1.0f,1.0f,
		1.0f,1.0f
	};

	///材质
	static const GLfloat tex[] = {
		0.0f,1.0f,
		1.0f,1.0f,
		0.0f,0.0f,
		1.0f,0.0f
	};
	///传递顶点坐标
	glVertexAttribPointer(A_VER, 2, GL_FLOAT, 0, 0, ver);
	glEnableVertexAttribArray(A_VER);

	///传递材质坐标
	glVertexAttribPointer(T_VER, 2, GL_FLOAT, 0, 0, tex);
	glEnableVertexAttribArray(T_VER);

	///从shader中获取材质
	unis[0] = m_pProgram.uniformLocation("tex_y");
	unis[1] = m_pProgram.uniformLocation("tex_u");
	unis[2] = m_pProgram.uniformLocation("tex_v");

#if 0
	fp = fopen("out240x128.yuv","rb");
	if (!fp)
	{
		debug_out << "打开失败";
	}
#endif
	
#if 0
	QTimer * timer = new QTimer(this);
	QObject::connect(timer, &QTimer::timeout, this,static_cast<void (QOpenGLWidget::*)()>(&QOpenGLWidget::update));
	timer->start(30);
#endif
}

void XVideoWidget::resizeGL(int w, int h)
{
	Q_UNUSED(w);
	Q_UNUSED(h);
	QMutexLocker locker(&m_mut);
}

void XVideoWidget::paintGL()
{
#if 0
	if (feof(fp))
	{
		fseek(fp, 0, SEEK_SET);
	}
	fread(datas[0], 1, m_nWidth * m_nHeight, fp);
	fread(datas[1], 1, m_nWidth * m_nHeight / 4, fp);
	fread(datas[2], 1, m_nWidth * m_nHeight / 4, fp);
#endif
	QMutexLocker locker(&m_mut);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texs[0]);///0层绑定到Y材质
	///修改材质内容(复制内存中的内容）
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, m_nWidth, m_nHeight, GL_RED, GL_UNSIGNED_BYTE, datas[0]);
	///关联shader的变量
	glUniform1i(unis[0], 0);

	glActiveTexture(GL_TEXTURE0 + 1);
	glBindTexture(GL_TEXTURE_2D, texs[1]);///1层绑定到U材质
	///修改材质内容(复制内存中的内容）
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, m_nWidth  / 2, m_nHeight / 2, GL_RED, GL_UNSIGNED_BYTE, datas[1]);
	///关联shader的变量
	glUniform1i(unis[1], 1);

	glActiveTexture(GL_TEXTURE0 + 2);
	glBindTexture(GL_TEXTURE_2D, texs[2]);///2层绑定到V材质
	///修改材质内容(复制内存中的内容）
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, m_nWidth / 2, m_nHeight / 2, GL_RED, GL_UNSIGNED_BYTE, datas[2]);
	///关联shader的变量
	glUniform1i(unis[2], 2);	

	///显示
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	//debug_out << "渲染一次" << '\n';
}
