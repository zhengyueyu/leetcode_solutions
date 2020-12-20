Singleton* getInstance() {
	//外层的判空防止多个进程请求创建实例时阻塞在lock处
	if(instance == nullptr) {
		lock();
		//此处判断为空防止多线程中，一个线程lock住临界区后创建实例，另一个线程也已经执行过上面的判空，导致重复创建实例
		if(instance == nullptr) {
			instance = new Singleton();
		}
		unlock();
	}
	return instance;
}