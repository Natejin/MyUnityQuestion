using System.Collections;
using System.Collections.Generic;
using UnityEngine;



[System.Serializable]
public class Data_Item
{
    public int ID;
    public ItemMainType itemType;

    public Data_Item(Data_Item data_Item)
    {
        this.ID = data_Item.ID;
        this.itemType = data_Item.itemType;
    }


    public Data_Item(int ID, ItemMainType itemType)
    {
        this.ID = ID;
        this.itemType = itemType;
    }
}

[System.Serializable]
public class Data_Item_Equip : Data_Item
{
    public int durability;


    public Data_Item_Equip(Data_Item_Equip data_Item) : base(data_Item)
    {
        this.ID = data_Item.ID;
        this.itemType = data_Item.itemType;
        this.durability = data_Item.durability;
    }

    public Data_Item_Equip(Data_Item data_Item) : base(data_Item)
    {
        this.ID = data_Item.ID;
        this.itemType = data_Item.itemType;
        //this.durability = 10;
    }

    public Data_Item_Equip(int ID, ItemMainType itemType, int durability) : base(ID, itemType)
    {

        this.ID = ID;
        this.itemType = itemType;
        this.durability = durability;

    }
}

[System.Serializable]
public class Data_Item_Use : Data_Item
{
    public ItemEffect itemEffect;
    public int amount;

    public Data_Item_Use(Data_Item_Use data_Item) : base(data_Item)
    {
        this.ID = data_Item.ID;
        this.itemType = data_Item.itemType;
        this.amount = data_Item.amount;
    }

    public Data_Item_Use(int ID, ItemMainType itemType, int amount) : base(ID, itemType)
    {
        this.ID = ID;
        this.itemType = itemType;
        this.amount = amount;
    }
}



[System.Serializable]
public class Data_Item_Equip_Weapon : Data_Item_Equip
{
    public int damage;

    public Data_Item_Equip_Weapon(Data_Item_Equip_Weapon data_Item) : base(data_Item)
    {
        this.ID = data_Item.ID;
        this.itemType = data_Item.itemType;
        this.durability = data_Item.durability;
        this.damage = data_Item.damage;
    }

    public Data_Item_Equip_Weapon(int ID, ItemMainType itemType, int durability, int damage) : base(ID, itemType, durability)
    {

        this.ID = ID;
        this.itemType = itemType;
        this.durability = durability;
        this.damage = damage;

    }
}

[System.Serializable]
public class Data_Item_Equip_Armor : Data_Item_Equip
{
    public int armor;

    public Data_Item_Equip_Armor(Data_Item_Equip_Armor data_Item) : base(data_Item)
    {
        this.armor = data_Item.armor;
    }

    public Data_Item_Equip_Armor(int ID, ItemMainType itemType, int durability, int armor) : base(ID, itemType, durability)
    {
        this.armor = armor;
    }
}