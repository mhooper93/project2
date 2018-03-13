///////////////////////////////////////////////////////////////////////////////
// maxprotein_timing.cc
//
// Example code showing how to run each algorithm while measuring
// elapsed times precisely. You should modify this program to gather
// all of your experimental data.
//
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

#include "maxprotein.hh"
#include "timer.hh"

using namespace std;

void print_bar() {
  cout << string(79, '-') << endl;
}

int main() {

  const int n = 10,
    total_kcal = 1000;

  auto all_foods = load_usda_abbrev("ABBREV.txt");
  assert( all_foods );

  auto n_foods = filter_food_vector(*all_foods, 0, INT_MAX, n);
  assert( n_foods );
  assert( n_foods->size() == n );
  
  double elapsed;
  Timer timer;

  print_bar();
  cout << "n=" << n << ", total_kcal=" << total_kcal << endl;

  print_bar();
  timer.reset();
  auto greedy_solution = greedy_max_protein(*n_foods, total_kcal);
  elapsed = timer.elapsed();
  assert(greedy_solution);
  cout << "greedy solution:" << endl;
  print_food_vector(*greedy_solution);
  cout << "elapsed time=" << elapsed << " seconds" << endl;

  print_bar();
  if (n >= 64) {
    cout << "(n too large, skipping exhaustive search)" << endl;
  } else {
    timer.reset();
    auto exhaustive_solution = exhaustive_max_protein(*n_foods, total_kcal);
    elapsed = timer.elapsed();
    assert(exhaustive_solution);
    cout << "exhaustive solution:" << endl;
    print_food_vector(*exhaustive_solution);
    cout << "elapsed time=" << elapsed << " seconds" << endl;
  }
  print_bar();

  return 0;
}
