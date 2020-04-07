//
// Created by joey on 4/7/20.
//

#include "binarytree/common_parent_node.h"

void commomParentNode()
{
    int num1{}, num2{};
    while(cin >> num1 >> num2)
    {
        while(num1 > 0 && num2 > 0)
        {
            if(num1 > num2)
            {
                num1 = num1 / 2;
            }
            else if(num2 > num1)
            {
                num2 = num2 / 2;
            }
            else
            {
                cout<<num1<<endl;
                break;
            }
        }
    }
}