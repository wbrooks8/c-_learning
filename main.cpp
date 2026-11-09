#include <algorithm>

#include "Lesson12/lesson12.h"
#include "Lesson13/lesson13.h"
#include "Lesson14/lesson14.h"
#include "LessonCF/lessoncf.h"
#include "lesson15.h"

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include "Lesson16/lesson16.h"

// ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//   int l1 {0};
//   int l2 {0};
//   ListNode newList {};
//
//   int total = list1.size() + list2.size() - 2;
//
//   for (int i = 0; i <= total ; ++i) {
//     if (list1[l1] < list2[l2]) {
//
//     }
//   }
//
// }

void nextPermutation(std::vector<int>& nums) {
  for(int i {static_cast<int>(nums.size()) - 1}; i > 0; --i){
    for(int j {i}; j > 0; --j){
      if(nums[i] > nums[j]) {
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
        return;
      }
    }
  }

  std::reverse(nums.begin(), nums.end());

}

int main() {

  // lesson14::runLesson();

  // lesson15::runLesson();

  std::vector<int> nums = {1,3,2};

  nextPermutation(nums);

  for (const auto& num : nums) {
    std::cout << num << " ";
  }

  lesson16::endOfChapter();
  lesson16::main();

  return 0;
}
