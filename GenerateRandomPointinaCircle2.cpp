#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
private:
	double radius, x_center, y_center;
public:
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    vector<double> randPoint() {
        double theta = 2 * M_PI * ((double)rand() / RAND_MAX);
        double len = sqrt((double)rand() / RAND_MAX) * radius;
        return {x_center + len * cos(theta), y_center + len * sin(theta)};
    }
};

int main() {
	
	double radius, x_center, y_center;
	cin>>radius>>x_center>>y_center;
	
	Solution *solution = new Solution(radius, x_center, y_center);
	
	for(int i = 0; i < 5; i++) {
		vector<double> point = solution->randPoint();
	
		cout<<point[0]<<" "<<point[1];
		cout<<endl;
	}
	
	return 0;
}
