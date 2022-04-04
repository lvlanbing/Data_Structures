//
// Created by fly on 2022/4/2.
//

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
int onesort(T& nums, int left, int right) {
    int i = left, j = right;
    int p = nums[left];
    while(i < j) {

        while(nums[j] >= p && i < j) {
            j--;
        }

        while(nums[i] <= p && i < j) {
            i++;
        }

        if(i < j)
            swap(nums[i], nums[j]);
    }
    nums[left] = nums[i];
    nums[i] = p;
    return left;
}

template<typename T>
void sort(T& nums, int left, int right) {

    if(left < right) {
        int mid = onesort(nums, left, right);
        sort(nums, left, mid - 1);
        sort(nums, mid + 1, right);
    }

}

int main() {
    vector<int> nums = {2,2,4,1,3,4,6,7};
    int nums2[] = {2,3,4,1,3,4,6,7};
    string str = "68234556713151";
    sort(nums, 0, 7);
    sort(nums2, 0, 7);

    sort(str, 0,str.size() - 1);

    for(int i = 0; i < 8; ++i) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    for(int num : nums2)
        cout<<num<<" ";
    cout<<endl<<str;
}