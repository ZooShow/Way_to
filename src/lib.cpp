#include "lib.h"

int Way_to(string from, string to, Road *mass) {

    int result = 0, c_points = 1;
    int dest = 0, arr = 0;

    for (int i = 1; i < V; i++) {  //количество городов
        if (mass[i - 1].from != mass[i].from) {
            c_points++;
        }
    }

    string *towns = new string[c_points];
    towns[0] = "A";
    int koeef = 1;
    for (int i = 1; i < V; i++) {
        if (mass[i - 1].from != mass[i].from) {
            towns[koeef] = mass[i].from;        //массив городов
            koeef++;
        }
    }

    for (int i = 0; i < c_points; i++) {      //Выесняем строку и столбец искомого элемента в матрице
        if (towns[i] == from) {
            dest = i;
        } else if (towns[i] == to) {
            arr = i;
        }
    }

    int weight[c_points][c_points]; //массив весов
    int m = 0;

    for (int i = 0; i < c_points; i++) {
        for (int j = 0; j < c_points; j++) {

            if (i == j) {
                weight[i][j] = 0;
            } else if (towns[i] == mass[m].from && towns[j] == mass[m].to) {
                weight[i][j] = mass[m].dist;
            } else {
                weight[i][j] = 100000;
            }
            m++;
        }
    }

    for(int k = 0; k < c_points; k++){
        for(int i = 0; i < c_points; i++){
            for(int j = 0; j < c_points; j++){
                if(weight[i][k] + weight[k][j] < weight[i][j]){
                    weight[i][j] = weight[i][k] + weight[k][j];
                }
            }
        }
    }
    return weight[dest][arr];
}

void Read_file(Road* mas){
    int j=0;
    ifstream in ("../schedule.txt");
    string str, from_str, to_str, dis_str;
    for (int i=0; i<V; ++i){
        mas[i].from = "";
        mas[i].to = "";
        mas[i].dist = 0;
    }
    if (in.is_open()){
        while(!in.eof()){
            getline(in, str);
            from_str = str.substr(0, str.find(' '));
            str.erase(0, str.find(' ')+1);
            to_str = str.substr(0, str.find(' '));
            str.erase(0, str.find(' ')+1);
            dis_str = str;
            mas[j].from = from_str;
            mas[j].to = to_str;
            mas[j].dist = atoi(dis_str.c_str());
            ++j;
            }
        }
}