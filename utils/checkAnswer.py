def checkAnswers():
    original_ans = open("input_output\correct_ans.txt", 'r').readlines()
    outputed_ans = open("input_output/output.txt", 'r').readlines()

    original_ans = list(map(lambda x: x.strip("\n"), original_ans))
    outputed_ans = list(map(lambda x: x.strip("\n"), outputed_ans))

    if(len(original_ans) != len(outputed_ans)):
        print("[WA] No. of lines didn't match")
        return

    for i in range(len(original_ans)):
        string_orig = original_ans[i]
        string_output = outputed_ans[i]

        if(string_orig != string_output):
            print(f"[WA] wrong ans at {i + 1} line")
            print("Original ans:")
            print(original_ans)
            print("Output ans: ")
            print(outputed_ans)
            return

    print("[CA] Correct Ans")


if __name__ == "__main__":
    checkAnswers()
