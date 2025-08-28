#pragma once

#include <cstddef>
#include <vector>
#include <string>

static struct line {

    std::string data;

    std::size_t len;

} line;

namespace file {

    typedef enum file_type {

        BINARY, TEXT,

    } file_type;

    typedef struct file_data {

        std::string name;

        std::vector<struct line> lines;

        file_type type;

        std::size_t lines_num;
        std::size_t current_y;
        std::size_t current_x;

        std::size_t scroll_y;
        std::size_t scroll_x;

    } file_data;

    /// Basic method to see if a file is a binary.
    static bool is_binary(const std::string file);

    /// Reads a file into a file_data struct for the user to modify.
    file_data read_file(const std::string file_path);

    /// Write out a file_data to a file.
    void write_file(file_data data, const std::string file);

}