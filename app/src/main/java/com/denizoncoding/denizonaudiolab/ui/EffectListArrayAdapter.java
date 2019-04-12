/*
 * Copyright 2019 Deniz A. Atlihan
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.denizoncoding.denizonaudiolab.ui;

import android.content.Context;
import android.database.DataSetObserver;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CompoundButton;
import android.widget.ListAdapter;
import android.widget.SeekBar;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

import com.denizoncoding.denizonaudiolab.R;
import com.denizoncoding.denizonaudiolab.structure.DenizonEffect;

import java.util.LinkedList;

public class EffectListArrayAdapter implements ListAdapter {

    LinkedList<DenizonEffect> effectList;
    Context context;

    public EffectListArrayAdapter(Context context, LinkedList<DenizonEffect> effectList) {

        this.context = context;
        this.effectList = effectList;
    }


    @Override
    public View getView(int position, View convertView, ViewGroup parent) {

        DenizonEffect effect = effectList.get(position);

        return processView(convertView, effect);
    }

    private View processView(View convertView, DenizonEffect subjectData) {

//        LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
//        View rowView = inflater.inflate(R.layout.list_view_item_effects, null, true);

        Log.e("hey", "the funciton");
        if (convertView == null) {
            LayoutInflater layoutInflater = LayoutInflater.from(context);
            convertView = layoutInflater.inflate(R.layout.list_view_item_effects, null);
            final Switch switchOnOff = convertView.findViewById(R.id.switchOnOff);
            TextView effectGroupName = convertView.findViewById(R.id.textViewName);
            SeekBar testSeekBar = convertView.findViewById(R.id.seekBarTest);
            TextView testParam = convertView.findViewById(R.id.textViewTestParam);

            switchOnOff.setChecked(subjectData.isOn());
            effectGroupName.setText(subjectData.getName());
            switchOnOff.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {

                    Toast.makeText(context, "" + switchOnOff.isChecked(), Toast.LENGTH_SHORT).show();
                }
            });

        }
        return convertView;
    }

    @Override
    public boolean areAllItemsEnabled() {
        return true;
    }

    @Override
    public boolean isEnabled(int position) {
        return true;
    }

    @Override
    public void registerDataSetObserver(DataSetObserver observer) {

    }

    @Override
    public void unregisterDataSetObserver(DataSetObserver observer) {

    }

    @Override
    public int getCount() {
        return effectList.size();
    }

    @Override
    public Object getItem(int position) {
        return effectList.get(position);
    }

    @Override
    public long getItemId(int position) {
        return 0;
    }

    @Override
    public boolean hasStableIds() {
        return false;
    }

    @Override
    public int getItemViewType(int position) {
        return 0;
    }

    @Override
    public int getViewTypeCount() {
        return 1;
    }

    @Override
    public boolean isEmpty() {
        return effectList.isEmpty();
    }
}
