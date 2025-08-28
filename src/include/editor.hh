#pragma once

#include "file.hh"

#include <string>
#include <vector>
#include <cstddef>

class Editor {

public:

    Editor();
    ~Editor();

    void add_file(const std::string file_path);

    void init();

private:

    std::vector<file::file_data> files;
    std::size_t files_num;
    std::size_t current_file;

    int max_y, max_x;

    void display_file(std::size_t num);

    void load_tabs();
    void load_bar();

};