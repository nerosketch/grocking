//
// Created by ns on 7/17/20.
//

#ifndef GROCKING_BFS_TEMPLATE_HPP
#define GROCKING_BFS_TEMPLATE_HPP

#include <vector>
#include <memory>
//#include <deque>
#include <utility>
#include <iostream>

using namespace std;

/*
 * TODO: Ещё не доделал, работает пока не правильно.
 */

#define spGraphContainer shared_ptr<GraphContainer<T>>
#define spGraphContainers vector<spGraphContainer>
#define spItem shared_ptr<T>


template <class T>
class GraphContainer {
private:
    spGraphContainers _children;
    spItem _item;

    static spItem __searchItem(const spGraphContainers& children, const T *item)
    {
        for (const spGraphContainer& child : children)
        {
            const T& tl = *child->_item;
            cout << "Сравниваем " << tl << " и " << *item << endl;
            if (tl == *item)
            {
                cout << "  - Равны! Нашли :)" << endl;
                return child->_item;
            }
            cout << "  - не равны" << endl;
        }

        for (const spGraphContainer& child : children)
        {
            const auto& ec = *child->_item;
            cout << "Смотрим детей для " << ec << endl;
            if (child->_children.size() == 0)
            {
                cout << ec << "  - Пустой, следующий" << endl;
                continue;
            }
            cout << ec << "  - входим рекурсивно в " << ec << endl;
            spItem res = __searchItem(child->_children, item);
            if (res)
            {
                cout << ec << " вернул " << res << ", нашли!" << endl;
                return res;
            }
        }
        cout << "Ничего не нашли :(" << endl;
        return nullptr;
    }

public:
    GraphContainer(spItem item) : _item(move(item)), _children(0) {};
    GraphContainer(const T& item) : _item(make_shared<T>(item)), _children(0) {};
    virtual ~GraphContainer() = default;
    GraphContainer(const GraphContainer&) = default;

    void addItem(spItem item)
    {
        auto el = make_shared<GraphContainer<T>>(move(item));
        _children.push_back(el);
    }

    void addItem(const T& item)
    {
        addItem(make_shared<T>(item));
    }

//    void delItem(const T *pt)
//    {}

    spItem searchShortestItem(const T& item)
    {
        cout << "Ищем " << item << endl;
        return __searchItem(_children, &item);
    }
};

#endif //GROCKING_BFS_TEMPLATE_HPP
