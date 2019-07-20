package com.denizoncoding.denizonaudiolab.list;

import android.app.Activity;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.CompoundButton;
import android.widget.LinearLayout;
import android.widget.SeekBar;
import android.widget.Switch;
import android.widget.TextView;

import com.denizoncoding.denizonaudiolab.R;
import com.denizoncoding.denizonaudiolab.synth.Effect;
import com.denizoncoding.denizonaudiolab.synth.EffectParameter;

import java.util.List;

public class EffectsAdapter extends BaseAdapter {

    private LayoutInflater layoutInflater;
    private List<Effect> effectList;

    public EffectsAdapter(Activity activity, List<Effect> effectList) {

        layoutInflater = (LayoutInflater) activity.getSystemService(
                Context.LAYOUT_INFLATER_SERVICE);
        this.effectList = effectList;
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

        return effectList.get(position).getId();
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {

        View view = layoutInflater.inflate(R.layout.list_view_item, null);

        LinearLayout effectLayout = view.findViewById(R.id.verticalLayout);

        TextView nameText = (TextView) view.findViewById(R.id.effectName);

        Effect effect = effectList.get(position);
        nameText.setText(effect.getName());
        List<EffectParameter> parameterList = effect.getParameterList();

        for (final EffectParameter parameter : parameterList) {

            LinearLayout parameterLayout = new LinearLayout(view.getContext());

            if (parameter.isSwitchable()) {

                TextView parameterText = new TextView(view.getContext());
                parameterText.setTextSize(18f);
                parameterText.setLayoutParams(new LinearLayout.LayoutParams(
                        100,
                        LinearLayout.LayoutParams.WRAP_CONTENT));
                parameterText.setText(parameter.getName());

                Switch onOffSwitch = new Switch(view.getContext());
                onOffSwitch.setLayoutParams(new LinearLayout.LayoutParams(
                        200,
                        LinearLayout.LayoutParams.WRAP_CONTENT));

                onOffSwitch.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
                    @Override
                    public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {

                        if (isChecked) {
                            parameter.setValue(1);
                        } else {
                            parameter.setValue(0);
                        }
                    }
                });

                parameterLayout.addView(parameterText);
                parameterLayout.addView(onOffSwitch);

            } else {

                TextView parameterText = new TextView(view.getContext());
                parameterText.setTextSize(18f);
                parameterText.setLayoutParams(new LinearLayout.LayoutParams(
                        200,
                        LinearLayout.LayoutParams.WRAP_CONTENT));
                parameterText.setText(parameter.getName());

                SeekBar valueBar = new SeekBar(view.getContext());
                valueBar.setLayoutParams(new LinearLayout.LayoutParams(
                        500,
                        LinearLayout.LayoutParams.WRAP_CONTENT));
                valueBar.setMax(100);
                int progress = (int) (100 * ((parameter.getValue() - parameter.getMin()) / (parameter.getMax() - parameter.getMin())));
                valueBar.setProgress(progress);

                valueBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {

                    @Override
                    public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {

                        parameter.setValue(progress / 100f);
                    }

                    @Override
                    public void onStartTrackingTouch(SeekBar seekBar) {

                    }

                    @Override
                    public void onStopTrackingTouch(SeekBar seekBar) {

                    }
                });


                TextView valueText = new TextView(view.getContext());
                valueText.setTextSize(18f);
                valueText.setLayoutParams(new LinearLayout.LayoutParams(
                        200,
                        LinearLayout.LayoutParams.WRAP_CONTENT));
                valueText.setText(parameter.getName());

                valueText.setText("" + progress / 100f);

                parameterLayout.addView(parameterText);
                parameterLayout.addView(valueBar);
                parameterLayout.addView(valueText);
            }

            effectLayout.addView(parameterLayout);
        }

        return view;
    }
}
