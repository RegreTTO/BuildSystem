#include <map>
#include <vector>
class DependencyGraph {
private:
    std::map<const char*, std::vector<const char*>> graph;

    void init(const char* main_path);
    static void find_root();
public:
    DependencyGraph();
    ~DependencyGraph();

    
};