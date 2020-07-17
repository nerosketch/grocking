#include "bfs.h"

#include <iostream>
#include "bfs_template_before_learn.h"

using namespace std;


void breath_first_search()
{
    cout << "-=Поиск в ширину=-" << endl;
    GraphContainer<int> gc(12);
    gc.addItem(20);
    gc.addItem(30);
    gc.addItem(40);

    auto pres = gc.searchShortestItem(30);
    cout << "результат: " << *pres << endl;
}
