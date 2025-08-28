#include "include/file.hh"

#include <fstream>
#include <cctype>
#include <string>

namespace file {

    static bool is_binary(const std::string file_path) {
        std::ifstream f(file_path, std::ios::binary);

        if (!f) return false;

        size_t check_size = 1024;
        char buf[check_size];

        f.read(buf, check_size);

        size_t n = f.gcount();

        if (n == 0) return false;

        size_t nontext = 0;
        for (size_t i = 0; i < n; i++) {
            unsigned char c = buf[i];
            if (c == 0) return true;
            if (!(std::isprint(c) || std::isspace(c))) {
                nontext++;
            }
        }

        return nontext * 100 / n > 30;

    }

    file_data read_file(const std::string file_path) {
        file_data data;

        data.name = file_path;
        data.lines_num = 0;

        if (is_binary(file_path)) {
            data.type = BINARY;
        } else {
            data.type = TEXT;
        }

        std::ifstream f(file_path);

        std::string buf;
        while (std::getline(f, buf)) {
            data.lines[data.lines_num].data = buf;
            data.lines[data.lines_num].len = buf.length();
            data.lines_num++;
        }

        f.close();

        data.current_x = 0;
        data.current_y = 0;

        return data;
    }

    void write_file(file_data data, const std::string file_path) {
        std::ofstream f(file_path);

        for (const struct line l: data.lines) {
            f << l.data << "\n";
        }

        f.close();
    }

}