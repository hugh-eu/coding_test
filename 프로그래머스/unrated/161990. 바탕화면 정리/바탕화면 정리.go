import (
	"strings"
)

func solution(wallpaper []string) []int {
    
    var answer []int = []int{51, 51, -1, -1}

	for i, s := range wallpaper {
		if strings.Contains(s, "#") {
			if answer[0] > i {
				answer[0] = i
			}
			if answer[1] > len(strings.Split(s, "#")[0]) {
				answer[1] = len(strings.Split(s, "#")[0])
			}
			if answer[2] < i+1 {
				answer[2] = i + 1
			}
			if answer[3] < len(s)-len(strings.Split(s, "#")[len(strings.Split(s, "#"))-1]) {
				answer[3] = len(s) - len(strings.Split(s, "#")[len(strings.Split(s, "#"))-1])
			}
		}
	}
    
    return answer
}