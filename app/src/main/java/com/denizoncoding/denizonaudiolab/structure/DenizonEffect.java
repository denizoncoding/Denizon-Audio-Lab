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

package com.denizoncoding.denizonaudiolab.structure;

import java.util.LinkedList;

public class DenizonEffect {

    String name;
    boolean isOn;
    LinkedList<DenizonEffectParameter> parameters = new LinkedList<>();

    public DenizonEffect(String name, boolean isOn, LinkedList<DenizonEffectParameter> effects) {
        this.name = name;
        this.isOn = isOn;
        this.parameters = effects;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public boolean isOn() {
        return isOn;
    }

    public void setOn(boolean on) {
        isOn = on;
    }

    public LinkedList<DenizonEffectParameter> getParameters() {
        return parameters;
    }

    public void setParameters(LinkedList<DenizonEffectParameter> parameters) {
        this.parameters = parameters;
    }

}
