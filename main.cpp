#include <iostream>
#include <stack>
using namespace std;

#define TOWER 3
#define DISK 4

class Tower {
    stack<int> discs;
    int tower_index;
    public:
    Tower(int i) {
        tower_index = i;
    }

    void add(int n) {
        discs.push(n);
    }

    void move_top(Tower &destination) {
        // cout<<"Moving top: from "<<tower_index<<" to "<<destination.tower_index<<endl;
        if(discs.size() > 0) {
            int dk = discs.top();
            discs.pop();
            destination.add(dk);    
        }
    }

    void print_tower() {
        cout<<"Printing Tower "<<tower_index<<endl;
        cout<<"Size: "<<discs.size()<<endl;
        stack<int> temp;
        while(discs.empty() != true) {
            int dk = discs.top();
            discs.pop();
            cout<<dk<<endl;
            temp.push(dk);
        }
        while(temp.empty() != true) {
            int dk = temp.top();
            temp.pop();
            discs.push(dk);
        }
    }
};

void move_discs(int dsc, Tower &origin, Tower &destination, Tower &buffer) {
    if(dsc <= 0) return;
    
    move_discs(dsc - 1, origin, buffer, destination);
    
    origin.move_top(destination);
    
    move_discs(dsc - 1, buffer, destination, origin);
    
}

int main() {
    Tower t1(1), t2(2), t3(3);
    for(int i = DISK; i>0; i--) {
        t1.add(i);
    }
    
    move_discs(DISK, t1, t3, t2);
    t3.print_tower();
    
    return 0;
}
