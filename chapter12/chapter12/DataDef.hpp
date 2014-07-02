#ifndef DATA_DEFINE_HPP
#define DATA_DEFINE_HPP

#include <cstdint>
#include <string>


enum TIME_VALUE
{
    SECOND = 1,
    MINUTE = SECOND * 60,
    HOUR = MINUTE * 60,
    DAY = HOUR * 24,
    MONTH = DAY * 30,
};


enum ACCOUNT_TYPE
{
    PLAYER,
    GAMEMASTER,
    ADMINISTRATOR,
};


struct Point
{
    uint32_t x;
    uint32_t y;

    bool operator == (const Point &other)
    {
        return other.x == x && other.y == y;
    }
};


enum DIRECTION
{
    DIR_N,
    DIR_NE,
    DIR_E,
    DIR_SE,
    DIR_S,
    DIR_SW,
    DIR_W,
    DIR_NW,
};


struct LifeData
{
    uint32_t health;                        // ����ֵ
    uint32_t mana;                          // ����ֵ

    uint32_t health_limit;                  // ����ֵ����
    uint32_t mana_limit;                    // ����ֵ����

    uint32_t health_regen;                  // �����ָ�ֵ
    uint32_t mana_regen;                    // �����ָ�ֵ
};


struct DamagData
{
    uint32_t attack_damage_lower_limit;     // �����˺�����
    uint32_t attack_damage_upper_limit;     // �����˺�����

    uint32_t ability_power_lower_limit;     // ħ���˺�����
    uint32_t ability_power_upper_limit;     // ħ���˺�����

    uint32_t poison_damage_lower_limit;     // �����˺�����
    uint32_t poison_damage_upper_limit;     // �����˺�����
};


struct ResistData
{
    uint32_t armor_lower_limit;             // ��������
    uint32_t armor_upper_limit;             // ��������

    uint32_t magic_resist_lower_limit;      // ħ������
    uint32_t magic_resist_upper_limit;      // ħ������

    uint32_t spell_avoid;                   // ���ܶ�ܼ���
    uint32_t accuracy;                      // ��׼
    uint32_t agility;                       // ����
};


struct StrengthData
{
    uint32_t body_bear;                     // ���帺��
    uint32_t bag_bear;                      // ��������
    uint32_t grip;                          // ����
};


struct MapData
{
	//id ,map_id ���ĸ�map_nameΪɶΪint
    uint32_t id;                            // ID���
    std::string name;                       // ����

    uint32_t eject_map_id;                  // ���ߵ�ͼ���
    uint32_t eject_x;                       // ���ߵ�ͼX����
    uint32_t eject_y;                       // ���ߵ�ͼY����
};


struct DynamicObjectData
{
	//id, item_id���ĸ�
    uint64_t id;                            // ID���
    std::string name;                       // ����
};


struct ItemData
{
	//id,item_id
    uint64_t id;                            // ID���
    std::string name;                       // ����

    uint32_t level_limit;                   // �ȼ�����
    uint32_t career_limit;                  // ְҵ����

    uint32_t level;                         // �ȼ�
	//LifeDataֻ��ǰ�����ṹ
    LifeData life_data;                     // ����������
    DamagData damag_data;                   // �˺�
    ResistData resist_data;                 // ����
    //��������bag_bear,body_bear
	StrengthData streng_data;               // ����

    uint32_t lucky;                         // ����
    uint32_t curse;                         // ����

    uint32_t durability;                    // �־�
    uint32_t cool_down;                     // ��ȴʱ��

    bool can_repair;                        // �ܷ�����
    bool can_discard;                       // �ܷ���

    uint32_t consume_type;                  // ��������[�������ģ���ʱ���ģ�������]
    uint32_t overlap_limit;                 // ��Ʒ��������

    uint32_t weight;                        // ����
    std::string desc;                       // ��ϸ����
};


struct NpcData
{
	//npc_id ,id
    uint64_t id;                            // ID���
    std::string name;                       // ����

    uint32_t level;                         // �ȼ�
    uint32_t experience;                    // ��ɱ���õľ���

    LifeData life_data;                     // ����������
    DamagData damag_data;                   // �˺�
    ResistData resist_data;                 // ����

    uint32_t view_range;                    // ��Ұ
    //�����������ݿ���û��
    Point center;                           // �������
    uint32_t move_radius;                   // ��뾶
    uint32_t guard_radius;                  // �ػ��뾶

    uint32_t move_speed;                    // �ƶ��ٶ�
    uint32_t attack_speed;                  // �����ٶ�
   //���ݿ����и�desc����ϸ����
};

//û��career_data�ṹ��

struct PetData
{
	//id,pet_id
    uint32_t id;            // ID���
    std::string name;       // ����
};


struct SpellData
{
	//id,spell_id
    uint32_t id;            // ID���
    std::string name;       // ����
};

#endif