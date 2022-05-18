import React, { FunctionComponent } from "react";
import { ResponsiveLine } from "@nivo/line";

import { DiagramBaseProps } from "./types";
import { TooltipLine } from "../components/tooltip-line";
import {
  getyScaleOffset,
  enableArea,
  getyScale,
  getCurve,
  areaBaselineValue0,
  getMargins,
  getAxisLeftLegendOffset,
} from "../util/util";
import { sliceTooltip } from "../components/tooltip-slice";

export const LineDiagram: FunctionComponent<DiagramBaseProps> = (
  props: DiagramBaseProps
): React.ReactElement => {
  let format = "%H:%M";
  let tickValues = "every 3 hours";

  switch (props.precision) {
    case "week":
      format = "%d.%m";
      tickValues = "every 1 days";
      break;
    case "month":
      format = "%d.%m";
      tickValues = "every 3 days";
      break;
    case "year":
      format = "%d.%m";
      tickValues = "every 1 months";
      break;
    case "alltime":
      format = "%d.%m.%y";
      tickValues = "every 6 months";
      break;
  }

  let combinedData: any[] = [];
  if (props.data.length > 1) {
    for (const serie of props.data) {
      combinedData = [...combinedData, ...serie.data];
    }
  } else {
    combinedData = props.data[0].data;
  }

  let markers: any[] | undefined = [];
  if (props.observation === "temp") {
    markers = [
      ...markers,
      {
        axis: "y",
        value: 0,
        lineStyle: {
          stroke: "#00BFFF",
          strokeWidth: 2,
          strokeOpacity: 0.75,
          strokeDasharray: "10, 10",
        },
        // @todo Does only work with °C.
        legend: `0 ${props.unit}`,
        legendOrientation: "horizontal",
      },
    ];
  }

  return (
    <div className="diagram">
      <ResponsiveLine
        axisBottom={{
          format,
          tickValues,
          tickSize: 0,
          tickPadding: 5,
        }}
        axisLeft={{
          legend: props.unit,
          legendOffset: getAxisLeftLegendOffset(props.observation),
          legendPosition: "middle",
          tickSize: 0,
          tickPadding: 10,
        }}
        colors={props.color}
        curve={getCurve(props.observation)}
        data={props.data}
        enableArea={enableArea.includes(props.observation)}
        areaOpacity={props.observation === "wind" ? 0.5 : 0.07}
        areaBaselineValue={
          areaBaselineValue0.includes(props.observation)
            ? 0
            : Math.min(...combinedData.map((item) => item.y)) -
              getyScaleOffset(props.observation)
        }
        enableCrosshair={true}
        enablePoints={true}
        enableSlices={props.data.length > 1 ? "x" : false}
        sliceTooltip={(slice) => sliceTooltip(slice)}
        isInteractive={true}
        legends={
          props.data.length > 1
            ? [
                {
                  anchor: "top-right",
                  direction: "row",
                  itemWidth: 120,
                  itemHeight: 20,
                  itemsSpacing: 10,
                },
              ]
            : undefined
        }
        lineWidth={2}
        margin={getMargins(props.observation)}
        markers={markers}
        pointSize={5}
        tooltip={(point) => <TooltipLine point={point.point} />}
        useMesh={true}
        xScale={{
          precision: "minute",
          type: "time",
          format: "%s",
        }}
        yScale={getyScale(props.observation, combinedData)}
        xFormat="time:%Y/%m/%d %H:%M"
        yFormat={(value) => `${value} ${props.unit}`}
      />
    </div>
  );
};
