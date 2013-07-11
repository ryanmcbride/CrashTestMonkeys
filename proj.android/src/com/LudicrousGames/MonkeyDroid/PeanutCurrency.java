package com.LudicrousGames.MonkeyDroid;

import com.soomla.store.IStoreAssets;
import com.soomla.store.domain.GoogleMarketItem;
import com.soomla.store.domain.NonConsumableItem;
import com.soomla.store.domain.VirtualCategory;
import com.soomla.store.domain.virtualCurrencies.VirtualCurrency;
import com.soomla.store.domain.virtualCurrencies.VirtualCurrencyPack;
import com.soomla.store.domain.virtualGoods.SingleUseVG;
import com.soomla.store.domain.virtualGoods.VirtualGood;
import com.soomla.store.purchaseTypes.PurchaseWithMarket;
import com.soomla.store.purchaseTypes.PurchaseWithVirtualItem;

import java.util.ArrayList;
import java.util.Arrays;


public class PeanutCurrency implements IStoreAssets  {
	@Override
    public int getVersion() {
        return 0;
    }

    @Override
    public VirtualCurrency[] getCurrencies(){
        return  new VirtualCurrency[] {
                PEANUT_CURRENCY
        };
    }

    @Override
    public VirtualGood[] getGoods(){
        return new VirtualGood[] {MUFFINCAKE_GOOD};
    }

    @Override
    public VirtualCurrencyPack[] getCurrencyPacks(){
        return new VirtualCurrencyPack[] {
                TENMUFF_PACK, FIFTYMUFF_PACK, FOURHUNDMUFF_PACK, THOUSANDMUFF_PACK
        };
    }

    @Override
    public VirtualCategory[] getCategories() {
        return new VirtualCategory[]{
                GENERAL_CATEGORY
        };
    }

    @Override
    public NonConsumableItem[] getNonConsumableItems() {
        return new NonConsumableItem[]{
                NO_ADDS_NONCONS
        };
    }


    /** Static Final members **/

    public static final String PEANUT_CURRENCY_ITEM_ID      = "currency_peanut";
    public static final String TENMUFF_PACK_PRODUCT_ID      = "peanuts_3000";
    public static final String FIFTYMUFF_PACK_PRODUCT_ID    = "peanuts_35000";
    public static final String FOURHUNDMUFF_PACK_PRODUCT_ID = "peanuts_100000";
    public static final String THOUSANDMUFF_PACK_PRODUCT_ID = "peanuts_300000";


    /** Virtual Currencies **/
    public static final VirtualCurrency PEANUT_CURRENCY = new VirtualCurrency(
            "Peanuts",
            "",
            PEANUT_CURRENCY_ITEM_ID
    );

    /** Virtual Currency Packs **/

    public static final VirtualCurrencyPack TENMUFF_PACK = new VirtualCurrencyPack(
            "10 Muffins",                                   // name
            "Test refund of an item",                       // description
            "peanuts_3000",                                   // item id
            10,                                             // number of currencies in the pack
            PEANUT_CURRENCY_ITEM_ID,                                // the currency associated with this pack
            new PurchaseWithMarket(TENMUFF_PACK_PRODUCT_ID, 1.99));

    public static final VirtualCurrencyPack FIFTYMUFF_PACK = new VirtualCurrencyPack(
            "50 Muffins",                                   // name
            "Test cancellation of an item",                 // description
            "peanuts_35000",                                   // item id
            50,                                             // number of currencies in the pack
            PEANUT_CURRENCY_ITEM_ID,                        // the currency associated with this pack
            new PurchaseWithMarket(FIFTYMUFF_PACK_PRODUCT_ID, 7.99));

    public static final VirtualCurrencyPack FOURHUNDMUFF_PACK = new VirtualCurrencyPack(
            "400 Muffins",                                  // name
            "Test purchase of an item",                     // description
            "peanuts_100000",                                  // item id
            400,                                            // number of currencies in the pack
            PEANUT_CURRENCY_ITEM_ID,                        // the currency associated with this pack
            new PurchaseWithMarket(FOURHUNDMUFF_PACK_PRODUCT_ID, 14.99));

    public static final VirtualCurrencyPack THOUSANDMUFF_PACK = new VirtualCurrencyPack(
            "1000 Muffins",                                 // name
            "Test item unavailable",                        // description
            "peanuts_300000",                                 // item id
            1000,                                           // number of currencies in the pack
            PEANUT_CURRENCY_ITEM_ID,                        // the currency associated with this pack
            new PurchaseWithMarket(THOUSANDMUFF_PACK_PRODUCT_ID, 24.99));

    public static final VirtualGood MUFFINCAKE_GOOD = new SingleUseVG(
            "Fruit Cake",                                       // name
            "Customers buy a double portion on each purchase of this cake", // description
            "fruit_cake",                                       // item id
            new PurchaseWithVirtualItem(PEANUT_CURRENCY_ITEM_ID, 225)); // the way this virtual good is purchased
 
    /** Virtual Categories **/

    // The muffin rush theme doesn't support categories, so we just put everything under a general category.
    // In case you're using Soomla' storefront, the order of the virtual goods in this array matters!
    public static final VirtualCategory GENERAL_CATEGORY = new VirtualCategory(
            "General", new ArrayList<String>(Arrays.asList(new String[]{"fruit_cake"}))
    );


    /** Google Non Consumable (MANAGED) Items **/

    public static final NonConsumableItem NO_ADDS_NONCONS  = new NonConsumableItem(
            "No Ads",
            "Test purchase of MANAGED item.",
            "no_ads",
            new PurchaseWithMarket(new GoogleMarketItem("no_ads", GoogleMarketItem.Managed.MANAGED , 1.99))
    );
}

