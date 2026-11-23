#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <iostream>


#define println(out) std::cout << (out) << "\n"

#define vDisplay(vector) do { for (int i = 0; i < vector.size(); i++) {println(vector[i]);} } while(0);

class RuleSet {
    public:
        std::string scope;
        std::vector<std::string> hitlist;
        std::vector<std::string> allowlist;

        void display() {
            println( "\x1b[4;37m Scope: \x1b[0m " + scope );
            println( "\x1b[4;37m Hitlist: \x1b[0m " );
            vDisplay(hitlist);
            println( "\x1b[4;37m Allowlist: \x1b[0m " );
            vDisplay(allowlist);
        }
};

static std::vector<RuleSet> rule_list;

int main(void) {

    println( "active" );

    std::string buf;

    std::ifstream fileptr( ".gitignore" );
    if (!fileptr.is_open()) {
        println( "No '.gitignore' found in directry" );
        exit(1);
    }

    std::string cwd( "\0", FILENAME_MAX+1 );
    const std::string root_dir = getcwd( &cwd[0], cwd.capacity() );

    std::string current_dir = root_dir;
    println ( "Project root set at: " + root_dir );

    RuleSet global_rules;
    global_rules.scope = current_dir;

    while (std::getline( fileptr, buf )) {
        if (buf[0] == '!') {
            global_rules.allowlist.push_back( buf );
        } else {
            global_rules.hitlist.push_back( buf );
        }
    }

    fileptr.close();
    global_rules.display();
    rule_list.push_back( global_rules );

    std::string target;
    std::string cmd
    ;
    for (int ζ = 0; ζ < rule_list.size(); ζ++) {
        for (int χ = 0; χ < rule_list[ζ].hitlist.size(); χ++) {
            target = rule_list[ζ].hitlist[χ];
            cmd = "rm ";
            if (target[-1] == '/') {
                cmd += "-r ";
            }
            cmd += target;
            system(cmd.c_str());
        }
    }
    



    







    return 0;
}