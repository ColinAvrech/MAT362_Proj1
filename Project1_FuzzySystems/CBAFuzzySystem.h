//
//  CBAFuzzySystem.hpp
//  Project1_FuzzySystems
//
//  Created by Avrech, Colin on 11/28/16.
//  Copyright © 2016 Avrech, Colin. All rights reserved.
//

/*
 TODO:
 Integrate libraries for
    Display:
        [] - Text
        [] - Graphs
    Input:
        [] - Mouse
        [] - Keyboard
    Parsing:
        [] - Equations
        [] - Regex
        [] - Strings
 
 WANTS:
    Export/Import of FuzzySystems
    ANFIS - Adaptive Network Based Fuzzy Inference Systems 
        User data used to tweak the neural networks
*/

#ifndef CBAFuzzySystem_h
#define CBAFuzzySystem_h

#include <string>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::string;

//TODO: Templatize FuzzySystem for different numeric types
class FuzzySystem //: public GraphableBaseClass
{
public:
    FuzzySystem();
    FuzzySystem(const FuzzySystem& fuzzyToCopy);
    ~FuzzySystem();
    
    void SetLabel(const string& newFuzzyName);
    bool SetTerms(const string& newTermRegex);
    bool SetDiscourse(const vector<float>& newDiscourseTerms);
    
    void ClearGrammar();
    bool AddGrammarRule(const string& ruleName, const string& ruleCondition);
    bool RemoveGrammarRule(const string& ruleName);

    void ClearSemantic();
    bool AddSemanticRule(const string& ruleName, const vector<string>& ruleCondition);
    bool RemoveSemanticRule(const string& ruleName);
    
private:
    string fuzzyName;
    string termRegex;
    vector<float> discourse;
    unordered_map<string, string> grammarRuleMap;
    unordered_map<string, vector<string>> semanticRuleMap;
};

#endif /* CBAFuzzySystem_h */
