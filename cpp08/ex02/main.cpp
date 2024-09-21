#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(12);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::const_iterator c_it = mstack.end();
    MutantStack<int>::reverse_iterator rb_it = mstack.rbegin();
    MutantStack<int>::reverse_iterator re_it = mstack.rend();
    MutantStack<int>::const_reverse_iterator c_rb_it = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator c_re_it = mstack.rend();

    std::cout << "rb_it: " << *rb_it << std::endl;
    std::cout << "re_it: " << *(--re_it) << std::endl;
    std::cout << "c_rb_it: " << *c_rb_it << std::endl;
    std::cout << "c_re_it: " << *(--c_re_it) << std::endl;

    *it = 8;
    ++it;
    --it;
    while (it != c_it)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << s.top() << std::endl;
    return 0;
}
