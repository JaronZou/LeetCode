/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> paths;
        for(int i = 0; i < path.length(); ++i) {
            if(path[i] != '/') {
                string token;
                while(i < path.length() && path[i] != '/') {
                    token.push_back(path[i]);
                    ++i;
                }
                // 遇到".."就把之前的路径弹出，当然，前提是前面有路径
                if(token == "..") {
                    if(!paths.empty()) {
                        paths.pop_back();
                    }
                }
                // 遇到"."直接忽略，其余的加入路径中。
                else if(token != ".") {
                    paths.push_back(token);
                }
            }
        }
        // 将路径中所有的token串起组成完整路径
        string result = "/";
        for(int i = 0; i < paths.size(); ++i) {
            result.append(paths[i]);
            result.append("/");
        }
        // 注意，结束后要删除最后一个'/'，如果只有一个'/'，那可以不删除
        if(paths.size() != 0) {
            result.pop_back();
        }
        return result;
    }
};
// @lc code=end

