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
#include "Lesson17/fantasyStore.h"
#include "Lesson17/lesson17.h"
#include "Lesson18/lesson18.h"

#include <chrono>

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

class Timer
{
private:
  // Type aliases to make accessing nested type easier
  using Clock = std::chrono::steady_clock;
  using Second = std::chrono::duration<double, std::ratio<1> >;

  std::chrono::time_point<Clock> m_beg{ Clock::now() };

public:

  void reset()
  {
    m_beg = Clock::now();
  }

  double elapsed() const
  {
    return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
  }
};

int main() {

  // lesson14::runLesson();

  // lesson15::runLesson();
Timer t;

  lesson18::runLesson();

  std::cout << "Time taken: " << t.elapsed() << " seconds\n";


  return 0;
}
