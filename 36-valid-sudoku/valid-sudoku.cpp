class Solution {
public:
    bool checkrows(vector<vector<char>>& board){
        for(int i = 0; i<9; i++){
            set<char> st;
            for(auto c : board[i]){
                if(c == '.') continue;
                else {
                    if(st.find(c) != st.end()){
                        return false;
                    } else {
                        st.insert(c);
                    }
                }
            }
        }
        return true;
    }
    bool checkcols(vector<vector<char>>& board){
        for(int j = 0; j<9; j++){
            set<char> st;
            for(int i = 0; i<9; i++){
                char c = board[i][j];
                if(c == '.') continue;
                else {
                    if(st.find(c) != st.end()){
                        return false;
                    } else {
                        st.insert(c);
                    }
                }
            }
        }
        return true;
    }
    bool checkgrid(vector<vector<char>>& board){
        int kx = 3, ky = 3;
        set<char> st;
        for(int rows = 0; rows < 3; rows++){
            for(int cols = 0; cols < 3; cols++){
                char c = board[rows][cols];
                if(c == '.') continue;
                else {
                    if(st.find(c) != st.end()){
                        return false;
                    } else {
                        st.insert(c);
                    }
                }
            }
        }
        st.clear();

        for(int rows = 0; rows < 3; rows++){
            for(int cols = 3; cols < 6; cols++){
                char c = board[rows][cols];
                if(c == '.') continue;
                else {
                    if(st.find(c) != st.end()){
                        return false;
                    } else {
                        st.insert(c);
                    }
                }
            }
        }
        st.clear();

        for(int rows = 0; rows < 3; rows++){
            for(int cols = 6; cols < 9; cols++){
                char c = board[rows][cols];
                if(c == '.') continue;
                else {
                    if(st.find(c) != st.end()){
                        return false;
                    } else {
                        st.insert(c);
                    }
                }
            }
        }
        st.clear();

        for(int rows = 3; rows < 6; rows++){
            for(int cols = 0; cols < 3; cols++){
                char c = board[rows][cols];
                if(c == '.') continue;
                else {
                    if(st.find(c) != st.end()){
                        return false;
                    } else {
                        st.insert(c);
                    }
                }
            }
        }
        st.clear();

        for(int rows = 3; rows < 6; rows++){
            for(int cols = 3; cols < 6; cols++){
                char c = board[rows][cols];
                if(c == '.') continue;
                else {
                    if(st.find(c) != st.end()){
                        return false;
                    } else {
                        st.insert(c);
                    }
                }
            }
        }
        st.clear();

        for(int rows = 3; rows < 6; rows++){
            for(int cols = 6; cols < 9; cols++){
                char c = board[rows][cols];
                if(c == '.') continue;
                else {
                    if(st.find(c) != st.end()){
                        return false;
                    } else {
                        st.insert(c);
                    }
                }
            }
        }
        st.clear();

        for(int rows = 6; rows < 9; rows++){
            for(int cols = 0; cols < 3; cols++){
                char c = board[rows][cols];
                if(c == '.') continue;
                else {
                    if(st.find(c) != st.end()){
                        return false;
                    } else {
                        st.insert(c);
                    }
                }
            }
        }
        st.clear();

        for(int rows = 6; rows < 9; rows++){
            for(int cols = 3; cols < 6; cols++){
                char c = board[rows][cols];
                if(c == '.') continue;
                else {
                    if(st.find(c) != st.end()){
                        return false;
                    } else {
                        st.insert(c);
                    }
                }
            }
        }
        st.clear();

        for(int rows = 6; rows < 9; rows++){
            for(int cols = 6; cols < 9; cols++){
                char c = board[rows][cols];
                if(c == '.') continue;
                else {
                    if(st.find(c) != st.end()){
                        return false;
                    } else {
                        st.insert(c);
                    }
                }
            }
        }
        st.clear();

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows = checkrows(board);
        bool cols = checkcols(board);
        bool grid = checkgrid(board);

        return rows&&cols&&grid;
    }
};