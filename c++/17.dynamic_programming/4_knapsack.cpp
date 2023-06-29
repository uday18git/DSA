// Given an array of {weight,value } and a knapsack(bori) of a weight W. 
// Find the maximum value of items that can be stolen and put into knapsack
// Note -> we either have to pick the full item or (1) or no item
//  example -> Value -> {60,100,150}
// Weight -> {15,30,40}
//  W = 50
//  possible combinations -> {15,30} -> 160 {40}->150 
// {15,30} better answer
// we cannot apply greedy technique here because the items are indivisible meaning , items are either taken or not taken as a whole
// way of thinking
// we will iterate through the items array and we have two options for each array ->
// take it -> minus from W (capacity of the array)
// not take it -> capacity remains same
//  let f(n,w) = be the maximum value of items we can take till item n and current capacity of knapsack W


