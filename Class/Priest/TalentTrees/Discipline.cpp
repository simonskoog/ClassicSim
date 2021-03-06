#include "Discipline.h"

#include "Talent.h"
#include "TalentStatIncrease.h"
#include "Priest.h"
#include "PriestSpells.h"

    Discipline::Discipline(Priest* priest) :
    TalentTree("Discipline", "Assets/priest/priest_curses.jpg"), priest(priest), spells(static_cast<PriestSpells*>(priest->get_spells())) {
    talent_names_to_locations = {
            {"Unbreakable Will", "1ML"},
            {"Wand Specialization", "1MR"},
            {"Silent Resolve", "2LL"},
            {"Improved Discipline Word: Pain", "2ML"},
            {"Discipline Focus", "2MR"},
            {"Improved Psychic Scream", "2RR"},
            {"Improved Mind Blast", "3ML"},
            {"Mind Flay", "3MR"},
            {"Improved Fade", "4LL"},
            {"Discipline Reach", "4ML"},
            {"Discipline Weaving", "4RR"},
            {"Silence", "5ML"},
            {"Vampiric Embrace", "5MR"},
            {"Divine Spirit", "6MR"},
            {"Darkness", "7ML"}
        };

    QMap<QString, Talent*> tier1 {
        {"1ML", new Talent(priest, this, "Unbreakable Will", "1ML", "Assets/spell/", 5,
                           "Increases your chance to resist Stun, Fear, and Silence effects by an additional %1%.",
                           QVector<QPair<unsigned, unsigned>> {{3, 3}})},
        {"1MR", new Talent(priest, this, "Wand Specialization", "1MR", "Assets/spell/", 5,
                           "Increases your damage with Wands by %1%.",
                           QVector<QPair<double, double>> {{5, 5}})}
    };
    add_talents(tier1);

    QMap<QString, Talent*> tier2 {
        {"2LL", new Talent(priest, this, "Silent Resolve", "2LL", "Assets/spell/", 5,
                           "Reduces the threat generated by your spells by %1%.",
                           QVector<QPair<unsigned, unsigned>> {{4, 4}})},
        {"2ML", new Talent(priest, this, "Improved Power Word: Fortitude", "2ML", "Assets/spell/", 2,
                           "Increases the effect of your Power Word: Fortitude and Prayer of Fortitude spells by %1%.",
                           QVector<QPair<unsigned, unsigned>> {{15, 15}})},
        {"2MR", new Talent(priest, this, "Improved Power Word: Shield", "2MR", "Assets/spell/", 3,
                           "Increases the damage absorbed by your Power Word: Shield by %1%.",
                           QVector<QPair<unsigned, unsigned>> {{5, 5}})},
        {"2RR", new Talent(priest, this, "Martyrdom", "2RR", "Assets/spell/", 2,
                           "Gives you a %1% chance to gain the Focused Casting effect that lasts for 6 sec after being the victim of a melee or ranged critical strike. The Focused Casting effect prevents you from losing casting time when taking damage and increases resistance to Interrupt effects by %2%.",
                           QVector<QPair<unsigned, unsigned>> {{50, 50},{10, 10}})}
    };
    add_talents(tier2);

    QMap<QString, Talent*> tier3 {
        {"3ML", new Talent(priest, this, "Inner Focus", "3ML", "Assets/spell/", 1,
                           "When activated, reduces the Mana cost of your next spell by 100% and increases its critical effect chance by 25% if it is capable of a critical effect.",
                           QVector<QPair<unsigned, unsigned>> {})},
        {"3MR", new Talent(priest, this, "Meditation", "3MR", "Assets/spell/", 3,
                           "Allows %1% of your Mana regeneration to continue while casting.",
                           QVector<QPair<unsigned, unsigned>> {{5, 5}})}
    };
    add_talents(tier3);

    QMap<QString, Talent*> tier4 {
        {"4LL", new Talent(priest, this, "Improved Inner Fire", "4LL", "Assets/spell/", 3,
                           "Increases the Armor bonus of your Inner Fire spell by %1%.",
                           QVector<QPair<unsigned, unsigned>> {{10, 10}})},
        {"4ML", new Talent(priest, this, "Mental Agility", "4ML", "Assets/spell/", 5,
                           "Reduces the mana cost of your instant cast spells by %1%.",
                           QVector<QPair<unsigned, unsigned>> {{2, 2}})},
        {"4RR", new Talent(priest, this, "Improved Mana Burn", "4RR", "Assets/spell/", 2,
                           "Reduces the casting time of your Mana Burn spell by %1 secs.",
                           QVector<QPair<double, double>> {{0.25, 0.25}})}
    };
    add_talents(tier4);

    QMap<QString, Talent*> tier5 {
        {"5ML", new Talent(priest, this, "Mental Strength", "5ML", "Assets/spell/", 5,
                           "Increases your maximum Mana by %1%.",
                           QVector<QPair<unsigned, unsigned>> {{2, 2}})},
        {"5MR", new Talent(priest, this, "Divine Spirit", "5MR", "Assets/spell/", 1,
                           "Holy power infuses the target, increasing their Spirit by 17 for 30 min.",
                           QVector<QPair<unsigned, unsigned>> {})}
    };
    add_talents(tier5);

    QMap<QString, Talent*> tier6 {
        {"6MR", new Talent(priest, this, "Force of Will", "6MR", "Assets/spell/", 5,
                           "Increases your spell damage by %1% and the critical strike chance of your offensive spells by %2%.",
                           QVector<QPair<unsigned, unsigned>> {{1, 1},{1, 1}})}
    };
    add_talents(tier6);

    QMap<QString, Talent*> tier7 {
        {"7ML", new Talent(priest, this, "Power Infusion", "7ML", "Assets/spell/", 1,
                           "Infuses the target with power, increasing their spell damage and healing by 20%.  Lasts 15 sec.",
                           QVector<QPair<unsigned, unsigned>> {})}
    };
    add_talents(tier7);

    talents["3MR"]->talent->set_bottom_child(talents["5MR"]->talent);
    talents["5MR"]->talent->set_parent(talents["3MR"]->talent);

    talents["5ML"]->talent->set_bottom_child(talents["7ML"]->talent);
    talents["7ML"]->talent->set_parent(talents["5ML"]->talent);
}
