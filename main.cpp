/*
 * Issues without copy constructor
 *
 * */
#include<iostream>
struct Point {
int x,y;
int* array;
void allocate(int size) {
    array = new int(size);
    }
void clear() {
    delete array;
    }
};
int main()
{
    Point p;
    p.x=1;
    p.y=2;
    p.allocate(10);
    p.array[0]=10;
    p.array[1]=20;
    std::cout<<p.array<<'\n';
    p.clear();
    Point p1 = p;
    std::cout<<p1.array<<'\n';
    std::cout<<p1.array[0]<<'\n';
    std::cout<<p1.array[0]<<'\n';
    return 0;
}
