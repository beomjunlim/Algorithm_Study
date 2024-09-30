#include <string>
#include <vector>
#include <string>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int max_minutes = stoi(video_len.substr(0,2));
    int max_seconds = stoi(video_len.substr(3,2));
    
    int op_start_minutes = stoi(op_start.substr(0,2));
    int op_start_seconds = stoi(op_start.substr(3,2));
    
    int op_end_minutes = stoi(op_end.substr(0,2));
    int op_end_seconds = stoi(op_end.substr(3,2));
    
    int minutes = stoi(pos.substr(0,2));
    int seconds = stoi(pos.substr(3,2));
    
    bool skip = false;
    
    if(op_start_minutes<=minutes&&minutes<=op_end_minutes){
        if(op_start_minutes==op_end_minutes){
            if(op_start_seconds>seconds||seconds>op_end_seconds)
                skip = false;
            else
                skip = true;
        }
        else{
            if(op_start_minutes==minutes&&seconds<op_start_seconds)
                skip = false;
            else if(op_end_minutes==minutes&&seconds>op_end_seconds)
                skip = false;
            else
                skip = true;
        }
    }
        
    if(skip){
        minutes = op_end_minutes;
        seconds = op_end_seconds;
    }
    
    
    for(int i=0; i<commands.size(); i++){
        if(commands[i]=="next"){
            bool end = false;
            seconds += 10;
            
            if(seconds>59){
                seconds -= 60;
                minutes++;
            }
            
            if(minutes>max_minutes)
                    end = true;
            else if(minutes==max_minutes&&seconds>max_seconds)
                    end = true;
            
            if(end){
                minutes = max_minutes;
                seconds = max_seconds;
            }
        }
        
        else if(commands[i]=="prev"){
            bool start = false;
            seconds -= 10;
            
            if(seconds<0){
                seconds += 60;
                minutes--;
            }
            
            if(minutes<0)
                start = true;
            
            if(start){
                minutes = 0;
                seconds = 0;
            }
        }
        
        skip = false;
        
        if(op_start_minutes<=minutes&&minutes<=op_end_minutes){
            if(op_start_minutes==op_end_minutes){
                if(op_start_seconds>seconds||seconds>op_end_seconds)
                    skip = false;
                else
                    skip = true;
            }
            else{
                if(op_start_minutes==minutes&&seconds<op_start_seconds)
                    skip = false;
                else if(op_end_minutes==minutes&&seconds>op_end_seconds)
                    skip = false;
                else
                    skip = true;
            }
        }
        
        if(skip){
            minutes = op_end_minutes;
            seconds = op_end_seconds;
        }
    }
    
    if(minutes<10){
        answer += "0";
    }

    answer += to_string(minutes);
    answer += ":";
        
    if(seconds<10){
        answer += "0";
    }
    
    answer += to_string(seconds);
    
    return answer;
}
