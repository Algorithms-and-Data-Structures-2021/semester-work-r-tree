#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <chrono>
#include <vector>

// подключаем вашу структуру данных
#include "RTree.h"

using namespace std;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};
RTree tree;
int main() {

  // Tip 1: входные аргументы позволяют более гибко контролировать параметры вашей программы
  const auto path = string (kDatasetPath)+"/insert/";
  const auto output_path = string (kProjectPath)+"/benchmark/result/benchmark_delete_result.csv";

  // работа с набором данных
  vector <string> folders = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10"};
  vector <string> files = {"100", "500", "1000", "5000", "10000","25000", "50000", "100000"};


  vector<float> dimensions = {0,0};
  for (const string& file : files) { // Проходим по всем 10 .csv файлам
    for (const string& folder : folders) { // Проходим по всем 10 папкам с файлами
      for (int i = 1; i < 11; i++) { // Запускаем замерку времени 10 раз

        string line = "1";
        auto input_file = ifstream(path + folder + "/" + file + ".csv");
        auto time_diff_search = chrono::nanoseconds::zero();
        cout << (path + folder + "/" + file + ".csv") << endl;

        // здесь находится участок кода, время которого необходимо замерить
        auto j = 1;
        if (input_file) {
          while (!line.empty()) {
            getline(input_file, line);
            if (line.empty()) {
              break;
            }
            j++;
            string delimiter = ",";
            string token1 = line.substr(0, line.find(delimiter));
            string token2 = line.substr(line.find(delimiter)+1);
            vector<float> coords;
            coords.push_back(static_cast<float>(stoi(token1)));
            coords.push_back(static_cast<float>(stoi(token2)));
            tree.insert(&coords,j);
            const auto time_point_before_search = chrono::steady_clock::now();
            tree.deleting(&coords,j);
            const auto time_point_after_search = chrono::steady_clock::now();
            time_diff_search += time_point_after_search - time_point_before_search;
          }
        }


        const auto time_elapsed_ns_insert = chrono::duration_cast<chrono::nanoseconds>(time_diff_search).count();
        cout << time_elapsed_ns_insert << endl;

        input_file.close();

        // Открываем файл для записи и вносим полученые данные
        auto output_file = fstream(output_path, ios::app);
        output_file <<  time_elapsed_ns_insert << endl;
        output_file.close();
      }
    }
  }
  return 0;
}

