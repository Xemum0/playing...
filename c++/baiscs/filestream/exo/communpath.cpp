#include <iostream>
#include <cstring>

int common_path(const char *const *names, int n, char sep) {
    int i, pos_len;
    for (int pos_len = 0; ; pos_len++) {
        for (int i = 0; i < n; i++) {
            if (names[i][pos_len] != '\0' && names[i][pos_len] == names[0][pos_len]) {
                continue;
            }
            while (pos_len > 0 && names[0][--pos_len] != sep);
            return pos_len;
        }
    }
    return 0;
}

int main() {
    const char *names[] = {
        "/home/me/user/temp/a",
        "/home/me/user/temp/a/d",
        "/home/me/user/temp/a/d",
    };
    int len = common_path(names, sizeof(names) / sizeof(const char*), '/');
    if (!len) {
       std::cout << "No common path\n";
    } else {
      std::cout << "Common path: " << std::string_view(names[0], len) << '\n';
    }
    return 0;
}
