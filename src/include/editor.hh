#pragma once

#include "file.hh"

#include <string>
#include <vector>
#include <cstddef>

class Editor {

public:

    Editor();

    void add_file(std::string file_path);

    void init();

private:

    std::vector<file::file_data> files;
    std::size_t files_num;

    void display_files();
    void load_bar();

};