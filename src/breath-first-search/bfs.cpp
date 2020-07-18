#include "bfs.h"

#include <memory>
#include <iostream>
#include <string>
//#include "bfs_template_before_learn.h"
#include "bfs_template_after_learn.hpp"

using namespace std;


#define make_gi(X) make_shared<GraphItem<string>>(X)

void breath_first_search()
{
    /*cout << "-=Поиск в ширину до прочтения главы о поиске в ширину=-" << endl;
    {
        GraphContainer<int> gc(12);
        gc.addItem(20);
        gc.addItem(30);
        gc.addItem(40);

        auto pres = gc.searchShortestItem(30);
        cout << "результат: " << *pres << endl;
    }*/

    cout << "-=Поиск в ширину после прочтения главы о поиске в ширину=-" << endl;
    {
        auto you = make_gi("you");
        auto alice = make_gi("alice");
        auto bob = make_gi("bob");
        auto clare = make_gi("clare");
        auto anuj = make_gi("anuj");
        auto peggy = make_gi("peggy");
        auto thom = make_gi("thom");
        auto jonny = make_gi("jonny");

        you->addChild(alice);
        you->addChild(bob);
        you->addChild(clare);

        bob->addChild(anuj);
        bob->addChild(peggy);

        alice->addChild(peggy);

        clare->addChild(thom);
        clare->addChild(jonny);

        auto res = you->findElement(peggy);
        if (res)
        {
            cout << "Нашли: " << *res << endl;
        } else {
            cout << "Не нашли: " << endl;
        }
    }
}
