#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, int> contentViews;

void updateContentView(const std::string& content_id, int count) {
    contentViews[content_id] += count;
}
int getContentView(const std::string& content_id) {
    return contentViews[content_id];
}

int main() {
    // Update content views
    updateContentView("content001", 10);
    updateContentView("content002", 5);
    updateContentView("content003", 20);
    updateContentView("content001", 15);

    std::cout << "View count for content001: " << getContentView("content001") << std::endl;
    std::cout << "View count for content002: " << getContentView("content002") << std::endl;
    std::cout << "View count for content003: " << getContentView("content003") << std::endl;
    std::cout << "View count for non-existent content: " << getContentView("content999") << std::endl;

    return 0;
}
