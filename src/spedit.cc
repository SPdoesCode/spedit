#include "include/editor.hh"

#include <cstddef>
#include <cstdlib>
#include <iostream>

int main(int argc, const char** argv) {

    if (argc < 2) {
        std::cout <<"Usage:\n" <<
                    "   spedit <files>\n";
        std::exit(1);
    }

    Editor e;

    for (std::size_t i = 1; i < argc; i++)
        e.add_file(argv[i]);

    e.init();

    std::exit(0);

}