class FizzBuzz {
private:
    int n;
    mutex a, b, c, d;

public:
    FizzBuzz(int n) {
        this->n = n;
        b.lock();
        c.lock();
        d.lock();
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        
        for(int i = 1; i <= n; i++) {
            a.lock();
            if(i % 3 == 0 && i % 5 != 0) printFizz();
            b.unlock();
        }
        
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        
        for(int i = 1; i <= n; i++) {
            b.lock();
            if(i % 3 != 0 && i % 5 == 0) printBuzz();
            c.unlock();
        }
        
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        
        for(int i = 1; i <= n; i++) {
            c.lock();
            if(i % 3 == 0 && i % 5 == 0) printFizzBuzz();
            d.unlock();
        }
        
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        
        for(int i = 1; i <= n; i++) {
            d.lock();
            if(i % 3 != 0 && i % 5 != 0) printNumber(i);
            a.unlock();
        }
        
    }
};