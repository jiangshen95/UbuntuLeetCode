#include<iostream>
#include<vector>

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
        double x_rand = (double)rand() / RAND_MAX * 2 * radius + x_center - radius;
        double y_rand = (double)rand() / RAND_MAX * 2 * radius + y_center - radius;
        while((x_rand - x_center) * (x_rand - x_center) + (y_rand - y_center) * (y_rand - y_center) > radius * radius) {
        	x_rand = (double)rand() / RAND_MAX * 2 * radius + x_center - radius;
        	y_rand = (double)rand() / RAND_MAX * 2 * radius + y_center - radius;
		}
		return {x_rand, y_rand};
//        if((x_rand - x_center) * (x_rand - x_center) + (y_rand - y_center) * (y_rand - y_center) <= radius) 
//			return {x_rand, y_rand};
//        else return randPoint();
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
