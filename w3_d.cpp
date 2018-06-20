//
// Created by Shubham Bakshi on 16/04/2018.
//

#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

struct Segment {
    int start, end;
};


bool compare_func(Segment &a, Segment &b)
{
    return a.start < b.start;
}

std::vector<int> optimal_points(std::vector<Segment> &segments) {
    std::vector<int> points;

    std::sort(segments.begin(), segments.end(), compare_func);
    auto earliest_end = 0;
    for (size_t i = 0; i < segments.size(); ++i) {

        auto segment = segments.at(i);

        if (i == 0) {
            earliest_end = segment.end;
        }

        if (segment.end < earliest_end) {
            earliest_end = segment.end;
        }

        if (segment.start > earliest_end) {
            points.push_back(earliest_end);
            earliest_end = segment.end;
        }
//        std::cout << earliest_end << std::endl;

    }
    points.push_back(earliest_end);
    return points;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }
    std::vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
}