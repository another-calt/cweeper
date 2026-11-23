#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <unistd.h>
#include <iostream>

#define println(out) std::cout << (out) << "\n"

class RuleSet {
    public:
        std::string scope;
        std::vector<std::string> hitlist;
        std::vector<std::string> allowlist;

        void serialize(std::string file_buf) {}
};

int main(void) {
    std::string cwd("\0", FILENAME_MAX+1);
    std::string root_dir = getcwd(&cwd[0], cwd.capacity());
    println(root_dir);


    return 0;
}