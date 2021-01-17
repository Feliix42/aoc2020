class QuestionaireGroup {
public:
    bool answers[26];

    QuestionaireGroup(int task_number);
    void clear(int task_number);
    unsigned int report();
};
