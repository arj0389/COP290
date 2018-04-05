
#include<iostream>
#include<vector>

using namespace std;

class three_d_point{
public:
int x,y,z;
        void setx(int a){
    x=a;
    }
    void setz(int a){
    z=a;
    }
    void sety(int b){
    y=b;
    }


    void show()
    {
    cout<<"The 3-D cartesian coordinates are: ("<<x<<","<<y<<","<<z<<")";
    }
    int x_extractor(){
    return x;
        }

        int y_extractor(){
    return y;
        }

        int z_extractor(){
    return z;
        }
};

class two_d_point{

public:

    int x,y;

    void setx(int a){
    x=a;
    }
int getx(){
    return x;
}
int gety(){
    return y;
}


     void sety(int b){
    y=b;
    }

    void show(){

    cout<<"("<<x<<","<<y<<")";

    }
};

class two_d_view{

public:

    vector <two_d_point> vec;

  /*  void show(){
    cout<<"value of the coordinates of all the points are"<<endl;
    for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<endl;
        }


    }*/
};


    class three_d_view{

public:

    vector <three_d_point> vec;

  /*  void show(){
    cout<<"value of the coordinates of all the points are"<<endl;
    for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<endl;
        }


    }*/
    };



