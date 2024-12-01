// you are given a complex 2D vector where student has marks in three subjects your task is to sort the vector such that total marks of studnets will be in ascending/descending order
#include <iostream>
#include <vector>
using namespace std;

int totalMarks(vector<int> s)
{
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ans += s[i];
    }
    return ans;
}

bool compare(pair<string, vector<int>> s1, pair<string, vector<int>> s2)
{
    vector<int> marks1 = s1.second;
    vector<int> marks2 = s2.second;

    int totalMarks1 = totalMarks(marks1);
    int totalMarks2 = totalMarks(marks2);

    return totalMarks1 > totalMarks2;
}

int main()
{
    vector<pair<string, vector<int>>> students = {
        {"Sagar", {99, 98, 100}},
        {"Shruti", {60, 35, 33}},
        {"Nidhi", {86, 88, 65}},
        {"Monika", {45, 65, 32}},
        {"Tushar", {87, 89, 57}},
    };

    sort(students.begin(), students.end(), compare);

    for (pair student : students)
    {
        cout << student.first << " " << totalMarks(student.second) << endl;
    }
    return 0;
}