#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <iostream>

#define println(out) std::cout << (out) << "\n"

#define vdisplay(vector) do { for (int i = 0; i < vector.size(); i++) {println(vector[i]);} } while(0);

class RuleSet {
    public:
        std::string scope;
        std::vector<std::string> hitlist;
        std::vector<std::string> allowlist;

        void display() {
            println("Scope: " + scope);
            println("Hitlist: ");
            vdisplay(hitlist);
            println("Allowlist: ");
            vdisplay(allowlist);
        }

        void serialize(std::string file, std::string cwd) {}
};

static std::vector<RuleSet> rule_list;

int main(void) {
    std::string buf;

    println("active");

    std::ifstream file_buf(".gitignore");
    if (!file_buf.is_open()) {
        println("No '.gitignore' found in directry");
        exit(1);
    }

    std::string cwd("\0", FILENAME_MAX+1);
    const std::string root_dir = getcwd(&cwd[0], cwd.capacity());
    std::string current_dir = root_dir;
    println("Project root set at: " + root_dir);

    RuleSet rules1;
    rules1.scope = current_dir;
    while (std::getline(file_buf, buf)) {
        if (buf[0] == '!') {
            rules1.allowlist.push_back(buf);
        } else {
            rules1.hitlist.push_back(buf);
        }
    }
    file_buf.close();

    rules1.display();
    rule_list.push_back(rules1);
    


    







    return 0;
}