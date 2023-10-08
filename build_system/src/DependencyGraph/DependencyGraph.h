#include <map>
#include <vector>
#include <regex>
class DependencyGraph {
private:
    std::map<const char*, std::vector<const char*>> graph;
    const char* MAIN_PATH = "";
    void init(const char* main_path);
    static void filetreeDFS(const char* starting_dir, short max_depth = 10);
public:
    static void find_main();
    DependencyGraph();
    ~DependencyGraph();

    
};