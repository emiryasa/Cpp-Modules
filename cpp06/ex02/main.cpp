#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
    int i = std::rand() % 3;

    switch (i)
    {
        case 0:
            return new A;
        case 1:
            return new B;
        default:
            return new C;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    } catch (std::exception &e) {
        try {
            B &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        } catch (std::exception &e) {
            try {
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;
            } catch (std::exception &e) {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}

int main() {
    
    std::srand(std::time(NULL));
    Base *base= generate();

    identify(base);
    identify(*base);

    delete base;
    return 0;
}
