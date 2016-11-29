//
//  CBAFuzzySystem.cpp
//  Project1_FuzzySystems
//
//  Created by Avrech, Colin on 11/28/16.
//  Copyright © 2016 Avrech, Colin. All rights reserved.
//

#include "CBAFuzzySystem.h"

FuzzySystem::FuzzySystem()
{
    fuzzyName = "NotSet";
    termRegex = "NotSet";
}

FuzzySystem::FuzzySystem(const FuzzySystem& fuzzyToCopy)
{
    fuzzyName = fuzzyToCopy.fuzzyName;
    termRegex = fuzzyToCopy.termRegex;
}

FuzzySystem::~FuzzySystem()
{
    grammarRuleMap.clear();
    semanticRuleMap.clear();
}

void FuzzySystem::SetLabel(const string& newFuzzyName)
{
    fuzzyName = newFuzzyName;
}

bool FuzzySystem::SetTerms(const string& newTermRegex)
{
    termRegex = newTermRegex;
    return false;
}

bool FuzzySystem::SetDiscourse(const vector<float>& newDiscourseTerms)
{
    discourse = newDiscourseTerms;
    return false;
}

void FuzzySystem::ClearGrammar()
{
    grammarRuleMap.clear();
}

bool FuzzySystem::AddGrammarRule(const string& ruleName, const string& ruleCondition)
{
    grammarRuleMap[ruleName] = ruleCondition;
    return false;
}

bool FuzzySystem::RemoveGrammarRule(const string& ruleName)
{
    grammarRuleMap.erase(ruleName);
    return false;
}

void FuzzySystem::ClearSemantic()
{
    semanticRuleMap.clear();
}

bool FuzzySystem::AddSemanticRule(const string& ruleName, const vector<string>& ruleCondition)
{
    semanticRuleMap[ruleName] = ruleCondition;
    return false;
}

bool FuzzySystem::RemoveSemanticRule(const string& ruleName)
{
    semanticRuleMap.erase(ruleName);
    return false;
}
