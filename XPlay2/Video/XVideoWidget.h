#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QGLShaderProgram>
#include "Interface/IVideoCall.h"

class XVideoWidget : public QOpenGLWidget ,protected QOpenGLFunctions ,public IVideoCall
{
	Q_OBJECT
public:
	XVideoWidget(QWidget *parent);
	~XVideoWidget();

///通过IVideoCall接口类重写
public:
	virtual void init(int nWidth, int nheight) override;

	virtual void paintVideo(AVFrame* frame) override;

///通过QOpenGLWidget重写
protected:
	///放入opengl所有初始化
	virtual void initializeGL() override;

	///opengl窗体发生改变
	virtual void resizeGL(int w, int h) override;

	///具体的渲染代码
	virtual void paintGL() override;
private:
	///加载shader程序
	QGLShaderProgram m_pProgram;

	///shader中yuv变量地址
	GLuint unis[3] = { 0 };

	///openg的 texture地址
	GLuint texs[3] = { 0 };

	///材质内存空间
	uint8_t* datas[3] = { 0 };

	int m_nWidth = 240;
	int m_nHeight = 128;
	QMutex m_mut;
};
