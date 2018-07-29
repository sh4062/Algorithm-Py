/*
 * File: thread.cpp
 * Project: 面向对象
 * File Created: Tuesday, 3rd July 2018 10:23:37 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 3rd July 2018 10:23:40 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#include "Thread.h"
#include <iostream>
using namespace oh;
struct TreadData {
	Thread & t;
	size_t idx;
};
Thread::Thread()
: _pthid(0)
, _isRunning(false)
{}


void Thread::start()
{
	pthread_create(&_pthid, NULL, threadFunc, this);
	_isRunning = true;
}

void * Thread::threadFunc(void * arg)
{
	Thread * pthread = static_cast<Thread*>(arg);
	if(pthread)
		pthread->run();// 执行任务

	return NULL;
}

void Thread::join()
{
	pthread_join(_pthid, NULL);
	_isRunning = false;
}

Thread::~Thread()
{
	if(_isRunning)	
	{
		pthread_detach(_pthid);// 将运行的线程交给系统进行托管
		_isRunning = false;
	}
}