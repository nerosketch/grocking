//
// Created by ns on 7/18/20.
//

#ifndef GROCKING_BFS_TEMPLATE_AFTER_LEARN_H
#define GROCKING_BFS_TEMPLATE_AFTER_LEARN_H

#include <list>
#include <memory>
#include <deque>
#include <utility>
#include <algorithm>

using namespace std;

#define spGraphItem shared_ptr<GraphItem<T>>
#define spGraphItems list<spGraphItem>
#define spItem shared_ptr<T>


template <class T>
ostream& operator << (ostream& os, const list<T*>& lst)
{
    os << "[";
    for (const auto& l : lst)
    {
        os << *l << ",";
    }
    os << "]";
    return os;
}


template <class T>
class GraphItem {
private:
    spItem _element;
    spGraphItems _children;

    static bool _list_contains(const list<T*>& watch_list, const T* p_item)
    {
        const auto& res_el = find(watch_list.begin(), watch_list.end(), p_item);
        return res_el != watch_list.end();
    }

public:
    GraphItem() = default;

    GraphItem(const spItem& i)
            :_element(i), _children(0)
    {
    }

    GraphItem(const T& i)
            :_element(make_shared<T>(i))
    {
    }

    GraphItem(const GraphItem&) = default;

    virtual ~GraphItem() = default;

    friend ostream& operator<<(ostream& os, const GraphItem& obj)
    {
        os << *obj._element;
        return os;
    }

    friend ostream& operator << (ostream& os, const deque<spGraphItem>& deq)
    {
        os << "{";
        for (const auto& el : deq)
        {
            os << *el->_element << ", ";
        }
        os << "}";
        return os;
    }

    void addChild(spGraphItem& item)
    {
        _children.push_back(item);
    }

    void addChild(const spItem& i)
    {
        spGraphItem newGraphItem = make_shared<GraphItem>(i);
        addChild(move(newGraphItem));
    }

    void addChild(const T& i)
    {
        spItem newEl = make_shared<T>(i);
        addChild(move(newEl));
    }

    spGraphItem findElement(const T& required_element)
    {
        deque<spGraphItem > deq;
        // заполняем очередь потомками текущего элемента
        deq.assign(_children.begin(), _children.end());

        cout << "Создали очередь, сейчас она:" << deq << endl;

        list<T*> checked;

        auto deq_it = deq.begin();
        while (deq_it != deq.end()) {
            spGraphItem& el = *deq_it;

            cout << "Проверяем элемент " << *el << ", сравниваем с " << required_element << endl;
            if (*el->_element == required_element) {
                // нашли
                return el;
            }

            if (_list_contains(checked, el->_element.get())) {
                // уже искали этот элемент
                cout << "уже искали этот элемент (" << *el << ")" << endl;

                deq_it ++;
                continue;
            }

            // добавляем всех потомков для проверки
            cout << "добавляем всех потомков для проверки" << endl;
            checked.push_back(el->_element.get());

            // Добавляем потомков el в конец очереди deq
            deq.insert(deq.cend(), el->_children.begin(), el->_children.end());

            cout << "Теперь список проверенных = " << checked << endl;
            cout << " -  очередь сейчас = " << deq << endl;

            deq_it ++;
        }

        // если дошли сюда значит ничего не нашли
        return nullptr;
    }

    spGraphItem findElement(const spGraphItem& required_element)
    {
        return findElement(*required_element->_element);
    }
};

#endif //GROCKING_BFS_TEMPLATE_AFTER_LEARN_H
