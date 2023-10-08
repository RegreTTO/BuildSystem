#include <map>
#include <vector>
#include <regex>
class DependencyGraph {
private:
    std::map<const char*, std::vector<const char*>> graph;
    const char* MAIN_PATH = "";
    void init(const char* main_path);
    static void find_main();
public:
    DependencyGraph();
    ~DependencyGraph();

    
};