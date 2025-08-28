#pragma once

#include "include/editor.hh"
#include "include/file.hh"

#include <cstdlib>
#include <iostream>
#include <string>

#include <termbox.h>

Editor::Editor() : files_num(0), current_file(0) {
    int err = tb_init();

    max_x = tb_width();
    max_y = tb_height();

    if (err != 0) {
        std::cout << "Error: Failed to init termbox (Error code " << err << ")!!\n";
        std::exit(1);
    }
}

Editor::~Editor() {
    tb_shutdown();
}

void Editor::add_file(const std::string file_path) {
    files.push_back(file::read_file(file_path));
}

void Editor::init() {
    tb_clear();

    while (true) {

    }
}

void Editor::load_tabs() {
    int i = 0;
    std::size_t j = 0;
    for (const file::file_data f: files) {
        std::string name = "["+f.name+"]";
        int fg = (current_file == j) ? TB_BLUE : TB_WHITE;
        for (const char c: name) {
            tb_change_cell(i, 0, c, fg, TB_BLACK);
            i++;
        }
        j++;
    }
}

void Editor::display_file(std::size_t num) {
    int i = 0;
    int j = 1;
    for (const struct line l: files[num].lines) {
        for (const char c: l.data) {
            tb_change_cell(i, j, c, TB_WHITE, TB_BLACK);
            i++;
        }
        j++;
    }
}